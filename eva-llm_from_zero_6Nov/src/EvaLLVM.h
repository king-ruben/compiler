
#ifndef EvaLLVM_h 
#define EvaLLVM_h

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"

#include "./parser/EvaParser.h"

class EvaLLVM{
   public:
    EvaLLVM() : parser(std::make_unique<syntax::EvaParser>()) {
        moduleInit();
        setupExternFunctions();
     }
    /**
     * Executes a program
    */
    void exec(const std::string &program){
        // 1. Parse the program
        auto ast = parser->parse(program);

        // 2. Compile to LLVM IR
        compile(ast);
        module->print(llvm::outs(), nullptr);
 
        // 3. Save module IR to file:
      saveModuleToFile("./out.ll");
    }

private:

    /**
     * Compiles an expression:
    */
    void compile(const Exp &ast){
        // 1. Create main function
          fn = createFunction("main",llvm::FunctionType::get(/* return type*/builder->getInt32Ty(),
                                                             /* varargs */false));
        // 2. Compile main body:
          gen(ast);
        //Cast to i32 to return from main
        //auto i32Result =
                //builder->CreateIntCast(result, builder->getInt32Ty(), true);

        builder->CreateRet(builder->getInt32(0));
    }

/**
 * Main compile loop:
*/
 llvm::Value* gen(const Exp &exp){

    switch (exp.type) {
        /**
         * --------------------------------------------------------------
         * Numbers
        */
       case ExpType::NUMBER:
        return builder->getInt32(exp.number);
        /**
         * --------------------------------------------------------------
         * Strings
        */
       case ExpType::STRING:
        return builder->CreateGlobalString(exp.string);
        /**
         * --------------------------------------------------------------
         * Symbols
        */
       case ExpType::SYMBOL:
       //TODO
        return builder->getInt32(0);

       case ExpType::LIST:
        auto tag = exp.list[0];

        /**
         * --------------------------------------------------------------
         * Special cases
        */

       if(tag.type == ExpType::SYMBOL) {
        auto op = tag.string;
        // --------------------------------------------------------------
        // printf: extern function:
        //
        // (printf "Value": %d 42)
         if(op == "printf"){
            auto printfFn = module->getFunction("printf");
            std::vector<llvm::Value*>args{};
            for(auto i = 1; i < exp.list.size();i++){
                args.push_back(gen(exp.list[i]));
            }
             return builder->CreateCall(printfFn, args);
        }
       }
    } 
    //Unreachable:
     return builder->getInt32(0);
 }

 
/**
 * Define external function (from libc++)
*/
void setupExternFunctions() {
    // i8* to substitute for char*, void*, etc
    auto bytePtrTy = builder->getInt8Ty()->getPointerTo();
    // int printf(const char* format, ...)
    module->getOrInsertFunction("printf",
     llvm::FunctionType::get(
      /*return type*/ builder->getInt32Ty(),
      /*format arg*/ bytePtrTy,
      /*vararg*/ true));
}

 /**
  * Creates a function 
 */
 llvm::Function* createFunction(const std::string &fnName, 
                                llvm::FunctionType* fnType)
{
    // Function prototype might already be definend:
    auto fn = module->getFunction(fnName);
    // If not, allocate the function:
    if (fn == nullptr){
        fn = createFunctionProto(fnName, fnType);
    }

    createFunctionBlock(fn);
    return fn;
}

/**
 * Creates function protype(defines the function but not the body)
*/

llvm::Function* createFunctionProto(const std::string &fnName,
                                    llvm::FunctionType* fnType) {

auto fn = llvm::Function::Create(fnType, llvm::Function::ExternalLinkage, fnName, *module);

verifyFunction(*fn);

return fn;
}

/**
 * Creates function block
*/
void createFunctionBlock(llvm::Function *fn){
    auto entry = createBB("Entry", fn);
    builder->SetInsertPoint(entry);
}

/**
 * 
*/
llvm::BasicBlock* createBB(std::string name, llvm::Function* fn = nullptr){
    return llvm::BasicBlock::Create(*ctx, name, fn);
}

/**
 * Saves IR to file
*/
void saveModuleToFile(const std::string &fileName){
    std::error_code errorCode;  
    llvm::raw_fd_ostream outLL(fileName, errorCode);
    module->print(outLL, nullptr);
}

/**
 * Initialize the module
*/
void moduleInit(){
    ctx = std::make_unique<llvm::LLVMContext>();   
    module = std::make_unique<llvm::Module>("EvaLLVM", *ctx);
    builder = std::make_unique<llvm::IRBuilder<>>(*ctx);
}

/**
 * Parser
*/
std::unique_ptr<syntax::EvaParser> parser;

/**
 * Currently compiling function
*/
llvm::Function* fn;
/**
 * Global LLVM context.
*/
std::unique_ptr<llvm::LLVMContext> ctx;

/**
 * Module
*/
std::unique_ptr<llvm::Module> module;

/**
 * IR Builder
*/

std::unique_ptr<llvm::IRBuilder<>> builder;

};




#endif