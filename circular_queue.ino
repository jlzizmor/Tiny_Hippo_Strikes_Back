/*
 * Jacob Zizmor
 * Group 1
 * Tiny Hippo
 * RBE 2002
 * D02 '14
 *
 * Circular Queue
 * circular_queue.ino
 *
 * This set of functions allows for the a float array to be implemented as a circular queue.
*/

// this function initializes the circular queue
// this function should be run once per queue at the beginning
void initCQ(float cq[]) {
	int size = sizeof(cq)/sizeof(float);
	for (int i = 0; i < size; i++) {
		cq[i] = -1;
	}
}

// this function queues a value to the circular queue
// pos is the index to add the the new value
// value is the new value to add
// after running, place is incremented
// because integers are passed by value, the incremented place is then returned
// the new value should be store by the user
int queue(float cq[], int pos, float value) {
	cq[pos] = value;
	pos += 1;
	return pos;
}

// this function returns the value at a specified index
// pos is the index of the value to be returned
int get(float cq[], int pos) {
	return cq[pos];
}