all: ss2 subsum_hw subsum_mod100
ss2: ss2.cpp
	clang++ -oss2 -g -fsanitize=undefined,address,integer ss2.cpp -std=c++14
subsum_hw: subsum_hw.cpp
	clang++ -osubsum_hw -g -fsanitize=undefined,address,integer subsum_hw.cpp -std=c++14
subsum_mod100: subsum_mod100.cpp
	clang++ -osubsum_mod100 -g -fsanitize=undefined,address,integer subsum_mod100.cpp -std=c++14
