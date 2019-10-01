void printlast10Lines(char* fileName) {
	const int K = 10;
	ifstream file (fileName);
	string L[K);
	int size = 0;
	/* read file line by line into circular array */
	/* peek() so an EOF following a line ending is not considered a separate line */
	while (file.peek() != EOF) {
		getline(file, L[size % K));
		size++;
	}

	/* compute start of circular array, and the size of it */
	int start size> K? (size% K) : 0;
	int count= min(K, size);
	/* print elements in the order they were read */
	for (inti= 0; i < count; i++) {
		cout << L[(start + i) % K] << endl;
	}
 }
