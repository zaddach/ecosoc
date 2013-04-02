#ifndef __INPUTDEP_H__
#define __INPUTDEP_H__

#include "llvm/Pass.h"
#include "llvm/Function.h"
#include "llvm/BasicBlock.h"
#include "llvm/Instruction.h"
#include "llvm/User.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/ADT/ilist.h"
#include "llvm/Instructions.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/Metadata.h"
#include "llvm/PassAnalysisSupport.h"
#include "llvm/Function.h"
#include "llvm/DepGraph.h"
#include "llvm/ADT/StringRef.h"
#include <string>

using namespace llvm;

class InputDep : public FunctionPass {
	private:
		void getInputDepFuns();
		bool runOnFunction(Function &F);
	public:
		static char ID;
		void getAnalysisUsage(AnalysisUsage &AU) const;
		InputDep();
};

//class AliasSets : public ModulePass {
//	std::map< int, std::set<Value*> > finalValueSets;
//	std::map< int, std::set<int> > finalMemSets;
//	std::map<int, std::set<int> > intSets;
//	std::map<int, std::set<int> > intPointsTo;
//	bool runOnModule(Module &M);
//	void printSets();
//	
//	public:
//	static char ID;
//	AliasSets();
//	void getAnalysisUsage(AnalysisUsage &AU) const;
//	std::map< int, std::set<Value*> > getValueSets();
//	std::map< int, std::set<int> > getMemSets();
//	int getValueSetKey(Value* v);
//	int getMapSetKey (int m);
//};

#endif
