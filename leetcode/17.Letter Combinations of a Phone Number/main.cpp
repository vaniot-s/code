//
// Created by vaniot on 18-12-15.
//

#include "main.h"

int main() {
    vector<string> res=main().letterCombinations("234");
    for (int i = 0; i <res.size() ; ++i) {
        cout<<res[i]<<endl;
    }
    return 0;
}