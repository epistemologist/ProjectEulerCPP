vector<int> gen_primes(int max_limit) {
	vector<bool> A(max_limit);
	vector<int> out;
	std::fill(begin(A), end(A), true);
	for (int i = 2; i*i < max_limit; i++) {
		if (A[i]) {
			for (int j = i*i; j < max_limit; j += i) {
				A[j] = false;
			}
		}
	}
	for (int i = 2; i < A.size(); i++) {
		if (A[i]) {
			out.push_back(i);
		}
	}
	return out;
}
