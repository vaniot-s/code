//
// Created by vaniot on 19-3-10.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
#define INTRODUCTION_TO_ALGORITHMS_SOLUTION_H


class solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto s : tokens){
            if (s != "+" && s != "-" && s != "*" && s != "/"){ //入栈
                st.push(std::stoi(s)); //
                continue;
            }
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (s[0]){
                case '+': st.push(b+a); break;
                case '-': st.push(b-a); break;
                case '*': st.push(b*a); break;
                case '/': st.push(b/a); break;
                default: break;
            }
        }
        return st.top();
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
