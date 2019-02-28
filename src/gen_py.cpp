#include <string>
#include <vector>
#include <iostream>
using namespace std;

int a, b, x;
string s;
int nest = 0;

void indentation(int nest){
  for(int i=0;i<nest;i++)cout << "\t";
}


int main(){
	while(cin >> s) {
    //nested syntaces
    if(s == "if"){//if begin syntax
      string condition;
      cin >> condition;
      indentation(nest);
      cout << "if "+ condition + ":"<< endl;
      nest++;
    }
    else if(s == "for"){//for syntax : for var iter
      string var,iter;
      cin >> var >> iter;
      indentation(nest);
      cout << "for "+ var + " in " + iter + ":" << endl;
      nest++;
    }
    else if(s == "while"){//while syntax : while condition
      string condition;
      cin >> condition;
      indentation(nest);
      cout << "while "+ condition + ":" << endl;
      nest++;
    }
    else if(s == "def"){//function definition syntax : def name argnum arg0, arg1...
      string name;
      int argnum;
      cin >> name >> argnum;
      string arg;
      vector<string > args;
      for (int i=0;i<argnum;i++){
        cin >> arg;
        args.push_back(arg);
      }
      indentation(nest);
      cout << "def " + name + "(";
      for(int i=0;i<args.size();i++){
        if(i)cout << ",";
        cout << args[i];
      }
      cout << "):" << endl;
      nest++;
    }
    else if(s == "end"){//end of control syntax
      nest--;
    }

    //non nested syntaces
    else if(s == "call"){//function call : call name arg
      string name;
      int argnum;
      cin >> name >> argnum;
      string arg;
      vector<string > args;
      for (int i=0;i<argnum;i++){
        cin >> arg;
        args.push_back(arg);
      }
      indentation(nest);
      cout << name + "(";
      for(int i=0;i<args.size();i++){
        if(i)cout << ",";
        cout << args[i];
      }
      cout << ")" << endl;
    }
    else if(s == "as"){//assignment of variable : as name val
      string name,val;
      cin >> name >> val;
      indentation(nest);
      cout << name + " = " + val << endl;
    }
    else if(s == "EOF"){
      break;
    }
    else{
      continue;
    }
	}
	return 0;
}
