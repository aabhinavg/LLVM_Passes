# Custom LLVM Pass Tutorial

Hello LLVM enthusiasts! If you're exploring the vast LLVM umbrella project and finding it challenging, understanding and implementing custom passes can be a great way to get more familiar with it.

## Basic Requirements:
- Knowledge of how to clone and build LLVM.

## Constant Folding Pass

This pass will implement the basic concept of constant folding in a compiler. If you're unfamiliar with constant folding, acquaint yourself with the concept before continuing.

1. **Clone LLVM and Build it:**
    ```bash
    $ WorkSpace = /yourlocation/llvm_project
    ```

2. **Create Header and Source Files:**
    Once LLVM is successfully built.
   - Create **MyConstantFolding.h** (header file for your custom pass) at location (*$WorkSpace/include/llvm/Transforms/Utils/MyConstantFolding.h*)
   - **MyConstantFolding.cpp** (name of your CPP file containing the pass) inside (*WorkSpace/lib/Transforms/Utils/MyConstantFolding.cpp*).

3. **Place Source File:**
   - Place the **MyConstantFolding.cpp** source file inside the location (*$WorkSpace/lib/Transforms/Utils/CMakeLists.txt*) along with other CPP files.
   - Ensure it is positioned below the last CPP file.

5. **Include Header in PassBuilder.cpp:**
   - Include your header file inside `PassBuilder.cpp` (`$WorkSpace/llvm/lib/Passes/PassBuilder.cpp`) as:
    ```cpp
    #include "llvm/Transforms/Utils/MyConstantFolding.h"
    ```
   - Make sure to place it below all the other header files inside `PassBuilder.cpp`.

6. **Register the Pass:**
    Register your pass inside (`$WorkSpace/llvm/lib/Passes/PassRegistry.def`) as:
    ```cpp
    FUNCTION_PASS("myconstantfolding", MyConstantFoldingPass()) // Registering my constant folding pass inside Function_Pass.
    ```

7. **Rebuild LLVM:**
    - Rebuild your LLVM.

8. **Run the Opt Tool:**
    - Run the `opt` tool on the LLVM given in the repo to see the change. Use the following command:
    ```bash
    /path/to/bin/opt -debug -passes=myconstantfolding /path/to/testcase/basic_constant.ll -S
    ```

9. **Check Output:**
    - You should be able to see the output as in `output.txt`.
    
Don't stop here; modify the code according to your needs, make changes, and observe how the Intermediate Representation (IR) changes.

