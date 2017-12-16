//
//  test_generation.h
//  Christofides
//
//  Created by Дмитрий Ткаченко on 16/12/2017.
//  Copyright © 2017 MIPT. All rights reserved.
//

#ifndef test_generation_h
#define test_generation_h

#define TESTS 10
#define VERTEX_MAX 1000
#define VERTEX_MIN 10

void gen_test(long long v, long long num) {
    
    set<pair<long long, long long>> s;
    
    string filename = "input" + to_string(num) + ".txt";
    
    freopen(filename.c_str(), "w", stdout);
    
    printf("%d %d\n", v, (v * (v - 1)) / 2);
    
    vector<long long> circ;
    
    for (long long i = 1; i <= v; i++) {
        circ.push_back(i);
    }
    
    random_shuffle(circ.begin(), circ.end());
    
    for (long long i = 0; i < circ.size() - 1; i++) {
        s.insert(make_pair(circ[i], circ[i + 1]));
        s.insert(make_pair(circ[i + 1], circ[i]));
        printf("1 %d %d\n", circ[i], circ[i + 1]);
    }
    
    s.insert(make_pair(circ[v - 1], circ[0]));
    s.insert(make_pair(circ[0], circ[v - 1]));
    printf("1 %d %d\n", circ[v - 1], circ[0]);
    
    for (long long i = 1; i <= v; i++) {
        for (long long j = 1; j <= v; j++) {
            
            if (i == j) {
                continue;
            }
            
            if (s.find(make_pair(i, j)) != s.end()) {
                continue;
            } else {
                int weight = random() % 2 + 1;
                s.insert(make_pair(i, j));
                s.insert(make_pair(j, i));
                printf("%d %d %d\n", weight, i, j);
            }
        }
    }
    
    fclose(stdout);
}

#endif /* test_generation_h */
