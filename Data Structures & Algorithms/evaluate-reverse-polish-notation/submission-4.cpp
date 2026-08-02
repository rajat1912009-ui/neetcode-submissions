class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> question;
        

        for(const string& token : tokens) {
            if(token == "+" || token == "-"  || token == "*" || token == "/") {
               int b = question.top(); question.pop();
               int a = question.top(); question.pop();
            
                if(token == "+") question.push(a + b);
                
                else if(token == "-") question.push(a - b);
                
                else if(token == "*") question.push(a * b);
                
                else if(token == "/") question.push(a / b);
                
              }  else {
                    question.push(stoi(token));
                }
            
        }
        return question.top();
        
    }
};
