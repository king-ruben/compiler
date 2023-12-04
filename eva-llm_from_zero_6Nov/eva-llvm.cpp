#include "./src/EvaLLVM.h"

int main(int argc, char const *argv[]){
    /**
     * Program to execute
    */
   std::string program = R"(
        (printf "Value: %d" 42)
   )";

   /**
    * Compiler instance
   */

  EvaLLVM vm;

  vm.exec(program);

    return 0;
}