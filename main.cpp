#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Node {
private:
	char Name;
	int Value;
public:
	Node();
    Node(char name);
	Node(char name,int value);
	virtual ~Node();
	char getName() const ;
	void setName(char name) ;
    int getValue() const ;
    void setValue(int value);
    friend ostream& operator<<(ostream& out,const Node& node ){
    	out<<node.Name<<": "<<node.Value<<endl;
    	return out;
    }
    int AND_operator(int frist_input,int second_input);
    int OR_operator(int frist_input,int second_input);
    int XOR_operator(int frist_input,int second_input);
};
class Gate {
protected:
	Node *InputNode1,*InputNode2,*OutputNode;
    string Type;
public:
	Gate();
    Gate(string t);
	Gate(Node* node1,Node* node2,Node *outnode);
	virtual ~Gate();


    void AND_operator(Node node1,Node node2,Node outnode);
    void OR_operator(Node node1,Node node2,Node outnode);
	void XOR_operator(Node node1,Node node2,Node outnode);
	void NAND_operator(Node node1,Node node2,Node outnode);
	void NOR_operator(Node node1,Node node2,Node outnode);
	void XNOR_operator(Node node1,Node node2,Node outnode);
	void NOT_operator(Node node1,Node outnode);
	void simulateGate(const string& type);

	const string& getType() const {
		return Type;
	}

	void setType(const string &type) {
		Type = type;
	}

	 Node* getInputNode1(){
		return InputNode1;
	}

	void setInputNode1(Node *inputNode1) {
		InputNode1 = inputNode1;
	}

	Node* getInputNode2(){
		return InputNode2;
	}

	void setInputNode2(Node *inputNode2) {
		InputNode2 = inputNode2;
	}

	Node* getOutputNode(){
		return OutputNode;
	}

	void setOutputNode( Node *outputNode) {
		OutputNode = outputNode;
	}
};
class Simulator{
private:
	   vector<Node*>arr_node;
	    vector<Gate*>arr_gate;
public:
	    Simulator();
	    void postnode(Node*nod);
	     void postgate(Gate*gat);
	     Node*findnode(char c);
	     void startsimulation();
	     void print();
	        void deletevector(char name);


	virtual ~Simulator();
};
class GateGenerator {
private:
public:
    Simulator s1;
    GateGenerator();
       void parseinput();
       Node*createnode(char s);
       Gate*creategate(string s);
	virtual ~GateGenerator();
};
Node::Node():Name(0),Value(0){}
Node::Node(char name):Name(name),Value(0){
}
Node::Node(char name,int value):Name(name),Value(value){}
char Node::getName() const {
		return Name;
    }
void Node:: setName(char name) {
		this->Name = name;
	}

int Node:: getValue() const {
		return Value;
	}

void Node::setValue(int value) {
		this->Value = value;

	}

int AND_operator(Node frist_input,Node second_input){
	if((frist_input.getValue()==0)||(second_input.getValue()==0)){
		return 0;
	}
	else{
		return 1;
	}
}
int OR_operator(Node frist_input,Node second_input){
	if((frist_input.getValue()==1)||(second_input.getValue()==1)){
		return 1;
	}
	else{
		return 0;
	}
}
int XOR_operator(Node frist_input,Node second_input){
	if((frist_input.getValue()==second_input.getValue())){
		return 0;
	}
	else{
		return 1;
	}
}
Node::~Node() {

}
Gate::Gate():InputNode1(nullptr),InputNode2(nullptr),
OutputNode(nullptr){}
Gate::Gate(string t):InputNode1(nullptr),InputNode2(nullptr),
		OutputNode(nullptr)
   {
	Type=t;
   }
Gate::Gate(Node* node1,Node* node2,Node *outnode):
		InputNode1(node1),InputNode2(node2),
		OutputNode(outnode){}


	void Gate:: AND_operator(Node node1,Node node2,Node outnode){
		if((node1.getValue()==0)||(node2.getValue()==0)){
			outnode.setValue(0);
			}
			else{
				outnode.setValue(1);
			}
	}

	void Gate::OR_operator(Node node1,Node node2,Node outnode){
		if((node1.getValue()==1)||(node2.getValue()==1)){
			outnode.setValue(1);
			}
			else{
				outnode.setValue(0);
			}

	}
	void Gate:: XOR_operator(Node node1,Node node2,Node outnode){
		if((node1.getValue()==node2.getValue())){
			outnode.setValue(0);
			}
			else{
				outnode.setValue(1);
			}

	}
	void Gate::NAND_operator(Node node1,Node node2,Node outnode){
		if((node1.getValue()==1)&&(node2.getValue()==1)){
			outnode.setValue(0);
			}
			else{
				outnode.setValue(1);
			}

	}
	void Gate::NOR_operator(Node node1,Node node2,Node outnode){
		if((node1.getValue()==0)&&(node2.getValue()==0)){
			outnode.setValue(1);
			}
			else{
				outnode.setValue(0);
			}

	}
	void Gate::XNOR_operator(Node node1,Node node2,Node outnode){
		if((node1.getValue()==node2.getValue())){
			outnode.setValue(1);
					}
					else{
						outnode.setValue(0);
					}

	}
	void Gate::NOT_operator(Node node1,Node outnode){
		if((node1.getValue()==1)){
			outnode.setValue(0);
			}
			else{
				outnode.setValue(1);
			}

	}

	void Gate::simulateGate(const string& type){
		if(type=="AND"){
			if ((InputNode1->getValue())&& ( InputNode2->getValue()) )

			        {
				OutputNode ->setValue(1);


			        }else
			        {
			        	OutputNode ->setValue(0);

			        }
		}
		else if(type=="OR"){
			if ((InputNode1->getValue())|| ( InputNode2->getValue()) )

						        {
							OutputNode ->setValue(1);


						        }else
						        {
						        	OutputNode ->setValue(0);

						        }
		}
		else if(type=="XOR"){
			if ((InputNode1->getValue())== ( InputNode2->getValue()) )

						        {
							OutputNode ->setValue(0);


						        }else
						        {
						        	OutputNode ->setValue(1);

						        }
		}
		else if(type=="NAND"){
			if ((InputNode1->getValue())&& ( InputNode2->getValue()) )

			        {
				OutputNode ->setValue(0);


			        }else
			        {
			        	OutputNode ->setValue(1);

			        }
		}
		else if(type=="NOR"){
			if ((InputNode1->getValue()==0)&& ( InputNode2->getValue()==0) )

			        {
				OutputNode ->setValue(1);


			        }else
			        {
			        	OutputNode ->setValue(0);

			        }
		}
		else if(type=="XNOR"){
			if ((InputNode1->getValue())== ( InputNode2->getValue()) )
				        {
								OutputNode ->setValue(1);
								 }else
								 {
								OutputNode ->setValue(0);
								}
		}
		else {
			if ((InputNode1->getValue()== 0))
			            {
				OutputNode ->setValue(1);
			            }

			            else
			            {
			            	OutputNode ->setValue(0);
			            }
		}



	}

Gate::~Gate() {
	// TODO Auto-generated destructor stub
}

Simulator::Simulator() {}

void Simulator::postnode(Node*nod)
     {
	arr_node.push_back(nod);
     }
void Simulator::postgate(Gate* gat)
     {
    	 arr_gate.push_back(gat);
     }
Node*Simulator::findnode(char c)
     {
         for( int i=0;i<(int)arr_node.size();i++)
         {
             if(arr_node[i]->getName()==c)
             {
                 return arr_node[i];
             }
         }
         return nullptr;
     }
void Simulator::startsimulation()
     {
         for(unsigned int i=0;i<arr_gate.size();i++)
         {
        	 arr_gate[i]->simulateGate(arr_gate[i]->getType());

         }
     }
void Simulator::print()
    {
        for(int i=0;i<(int)arr_node.size();i++)
        {

    cout<<*arr_node[i];
}
        }
        void Simulator::deletevector(char name)
        {
        	vector<Node*>::iterator it;
        for(it=arr_node.begin();it!=arr_node.end();it++)
        {
            if((*it)->getName()==name)
            {
            	arr_node.erase(it);
                break;
            }
        }

        }
Simulator::~Simulator() {

	// TODO Auto-generated destructor stub
}

    GateGenerator::GateGenerator(){}
void  GateGenerator:: parseinput()
{
    bool f=0;
   while(f==0)
   {
	   string s;
       cin>>s;

       if(s=="AND"||s=="OR"||s=="NAND"||s=="NOR"||s=="XOR"||s=="XNOR")
              {
                  char name1,name2,name3;
                  cin>>name1>>name2>>name3;

                   Node*firstnode= nullptr;
                 Node*secondnode= nullptr;
                 Node*resultnode=nullptr;

     if (s1.findnode(name1)==nullptr){
    	 firstnode= new Node (name1);
    	 s1.postnode(firstnode);
     }
     else{
    	 firstnode=s1.findnode(name1);
     }
     if(s1.findnode(name2)==nullptr)
                  {
                        secondnode = new Node (name2);
                        s1.postnode(secondnode);
                        }
                    else
                    {
                        secondnode=(s1.findnode(name2));

                    }
     if (s1.findnode(name3)==nullptr){
    	 resultnode= new Node (name3);
         	 s1.postnode(resultnode);
          }
          else{
        	  resultnode=s1.findnode(name3);
          }

     Gate*gatee=new Gate(s);
     gatee->setInputNode1(firstnode);
     gatee->setInputNode2(secondnode);
     gatee->setOutputNode(resultnode);
     s1.postgate(gatee);
              }
       else if(s=="NOT")
       {
           char name1,name2;
           cin>>name1>>name2;
       Node*firstnode;
           if (s1.findnode(name1)==nullptr){
               	 firstnode= new Node (name1);
               	 s1.postnode(firstnode);
                }
                else{
               	 firstnode=s1.findnode(name1);
                }
          Node*secondnode= new Node (name2);
           Gate*gatee=new Gate(s);
           gatee->setInputNode1(firstnode);
          gatee->setOutputNode(secondnode);
          s1.postnode(firstnode);
s1.postnode(secondnode);
s1.postgate(gatee);
       }
       else if(s=="SET")
       {
           char name1;
           bool value;
           cin>>name1 >>value;
Node*no=s1.findnode(name1);
no->setValue(value);

       }
       else if(s=="SIM")
       {s1.startsimulation();

       }
       else
       {
           string output;
           cin>>output;
           if(output=="ALL")
           {
               f=1;

s1.print();
           }
           else
           {
               Node*nodd=s1.findnode(output[0]);
               cout<<*nodd;
           }
       }

   }
}
Node* GateGenerator::createnode(char s)
{
    Node*p=new Node(s);
    return p;
}
Gate* GateGenerator::creategate(string s)
{
    Gate*pp=new Gate(s);
return pp;
}


GateGenerator::~GateGenerator() {
   delete Node (name1);
   delete name2;
   delete name3;
   delete s;
}


int main()
{
    GateGenerator g1;
    g1.parseinput();
    return 0;
}
