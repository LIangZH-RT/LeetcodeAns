#pragma once
#include<bits/stdc++.h>

class P81218 {
public:

    static void  P81218_A() {
        int size ; std::vector<int> v1; int m; std::vector<std::vector<int>> v2;
        std::cin >> size;
		v1.resize(size);
        for (int i = 0; i < size; i++) {
            std::cin >> v1[i];
        }

        std::cin >> m;
        v2.resize(m,std::vector<int>(2));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 2; j++) {
				std::cin >> v2[i][j];
            }
        }

        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            int b = v2[i][0]-1; int e = v2[i][1]-1;
            for (int j =b; j <= e ;j++) {
                ans += v1[j];
            }
            std::cout << ans << std::endl;
        } 
    }
};

