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
void initCQ(float cq) {
	int size = sizeof(cq)/sizeof(float);
	for (int i = 0; i < size; i++) {
		cq[i] = 0;
	}
}