/* Generated By:JJTree: Do not edit this line. ASTAndNode.cc Version 8.0 */
/* JavaCCOptions:MULTI=true,NODE_USES_PARSER=false,VISITOR=false,TRACK_TOKENS=true,NODE_PREFIX=AST,NODE_EXTENDS=MyNode,NODE_FACTORY=,SUPPORT_CLASS_VISIBILITY_PUBLIC=true */
#include "ASTAndNode.h"
#include "Boolean.h"

  
  ASTAndNode::ASTAndNode(int id) : Node(id) {
  }
  ASTAndNode::~ASTAndNode() {
  }
  void ASTAndNode::interpret()
  {
 #ifdef FAE
     jjtGetChild(0)->interpret();

	 const Node* top = stack.top();
	 if (typeid(*top) == typeid(Boolean)) {
		 const Boolean* boolean = (Boolean*)top;
		 if (!*boolean) {
			 stack.push(new Boolean(false));
			 return;
		 }
	 }
     jjtGetChild(1)->interpret();
 
	 unique_ptr<Boolean> left((Boolean*)stack.top()); stack.pop();
	 unique_ptr<Boolean> right((Boolean*)stack.top()); stack.pop();
     stack.push(new Boolean(*left && *right));
 #endif
  }


/* JavaCC - OriginalChecksum=420442a48eabdcbd7377019272a4568d (do not edit this line) */
