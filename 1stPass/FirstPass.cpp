#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
		struct FirstPass : public FunctionPass {
				static char ID;

				FirstPass() : FunctionPass(ID) {}

				bool runOnFunction(Function &F) override {
				errs() << "Function Name: ";
				errs() << (F.getName()) <<"\n" ;
				errs() << "number or argument " <<F.getName() <<" function takes: " << F.arg_size() <<"\n" ;
				return false;
				}
		}; // end of struct FirstPass
}  // end of anonymous namespace

char FirstPass::ID = 0;

static RegisterPass<FirstPass> X("firstpass1", "First Pass Pass");
