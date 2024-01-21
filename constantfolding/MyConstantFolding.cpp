#include "llvm/Transforms/Utils/MyConstantFolding.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Constants.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

PreservedAnalyses MyConstantFoldingPass::run(Function &F, FunctionAnalysisManager &AM) {
  bool update = false;
  errs() << "Inside the function for analyzing " << F.getName() << "\n";

  // Iterate over the basic blocks in the function
  for (BasicBlock &BB : F) {
    errs() << "Analyzing the basic block " << BB.getName() << " inside the function " << F.getName() << "\n";

    // Check if the basic block has instructions before iterating over instructions
    if (BB.size() == 0) {
      errs() << "No instructions inside the basic block " << BB.getName() << "\n";
      continue;
    }

    // Iterate over the instructions in the basic block
      for (auto I = BB.begin(); I != BB.end();) {
          Instruction &CurrI = *I;
          errs() << "Current instruction is: " << CurrI << "\n";
          ++I;
          
          // Get the operands of the instruction
          if (BinaryOperator *BO = dyn_cast<BinaryOperator>(&CurrI)) {
              Value *Op0 = BO->getOperand(0);
              Value *Op1 = BO->getOperand(1);
              
              Constant *Result = nullptr;
              
              // Check for constant integer operands
              if (isa<ConstantInt>(Op0) && isa<ConstantInt>(Op1)) {
                  ConstantInt *C1 = cast<ConstantInt>(Op0);
                  ConstantInt *C2 = cast<ConstantInt>(Op1);
                  
                  // Perform constant folding based on the opcode
                  switch (BO->getOpcode()) {
                      case Instruction::Add:
                          Result = ConstantExpr::getAdd(C1, C2);
                          break;
                      case Instruction::Sub:
                          Result = ConstantExpr::getSub(C1, C2);
                          break;
                      case Instruction::Mul:
                          Result = ConstantExpr::getMul(C1, C2);
                          break;
                      case Instruction::SDiv:
                          Result = ConstantInt::getSigned(C1->getType(), C1->getSExtValue() / C2->getSExtValue());
                          break;
                      case Instruction::UDiv:
                          Result = ConstantInt::get(C1->getType(), C1->getZExtValue() / C2->getZExtValue());
                          break;
                      default:
                          // Log a message for unsupported binary operation
                          errs() << "Warning: Unsupported binary operation in instruction: " << *BO << "\n";
                          continue;  // Skip the current iteration
                  }
                  
                  // Fold the instruction with the result for constant folding
                  if (Result) {
                      errs() << "ConstantFolded: " << *BO << " to " << *Result << "\n";
                      BO->replaceAllUsesWith(Result);
                      BO->eraseFromParent();
                      update = true;
                      
                  }
              } else {
                  // Log a message for non-constant operands if needed
                  errs() << "Warning: Non-constant operands in instruction: " << *BO << "\n";
              }
          }
      }
      // Print the updated IR after analyzing the entire function
       if (update) {
           errs() <<"Updated IR after complete Analyzing"<<"\n";
         errs() << "Updated IR after analyzing function " << F.getName() << ":\n";
           F.print(errs());
       }
      errs() <<"Updated IR after complete Analyzing"<<"\n";
      F.print(errs());
  }

  if (update)
      // Print the updated IR after analyzing the entire function
    return PreservedAnalyses::none();
  return PreservedAnalyses::all();
}
