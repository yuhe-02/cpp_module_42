#!/bin/bash

# 再ビルド
make re

# 手動テスト
echo "------ 手動引数テスト ------"
./PmergeMe 3 5 9 7 4 2 6 8 1

# ランダムテスト
# echo "------ ランダムテスト (1～10000の数字100個) ------"
# RANDOM_NUMS=$(for i in {1..3000}; do echo -n "$((RANDOM % 10000 + 1)) "; done)
# ./PmergeMe $RANDOM_NUMS
