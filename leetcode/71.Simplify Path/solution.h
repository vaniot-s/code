//
// Created by vaniot on 19-3-10.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
#define INTRODUCTION_TO_ALGORITHMS_SOLUTION_H


class solution {
public:
    string simplifyPath(string path) {
        stack<string> p;
        for(int i=0;i<len(path);i++){
            if(path[i]!="."&&path[i]!="/"){
                p.top()=p.top()+path[i];
                continue;
            }
            if (path[i]=="/") {
                if (p.top() == NULL) {
                    p.push(path[i]);
                    continue;
                }
                if (p.top() == ".") {
                    p.pop();
                    continue
                }
                if(path[i]=="/") continue;
                p.push();
            }
            if (path[i]==".") {
                if (p.top() == "/.") {
                    p.pop();
                    p.pop();
                    continue;
                }
                if (p.top() == "/") {
                    if(path[i+1]=="/"){
                        p.pop();
                        continue;
                    }
                    if (path[i+1]=="."){
                        p.push(path[i]);
                    }
                }

            }

        }

        string result;
        while (p.top!=NULL){
            result+=p.top();
            p.push;
        }
        return  result;
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_SOLUTION_H
