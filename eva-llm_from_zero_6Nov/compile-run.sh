# Compile main:
clang++ eva-llvm.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -o eva-llvm -fexceptions
# Run main:
./eva-llvm

# Execute generated IR:
lli ./out.ll

#Print result
echo $?
printf "\n"

