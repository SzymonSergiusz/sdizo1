#include <XCTest/XCTest.h>
#include "MaxHeap.hpp"

@interface MaxHeapTests : XCTestCase

@end

@implementation MaxHeapTests


- (void)testAdd {
    MaxHeap heap;
    heap.setLength(9);
    heap.add(3);
    heap.add(5);
    heap.add(2);
    heap.add(9);
    XCTAssertEqual(heap.getHeapSize(), 4);
    XCTAssertTrue(heap.search(3));
}

- (void)testDeleteByIndex {
    MaxHeap heap;
    heap.setLength(9);
    heap.add(3);
    heap.add(5);
    heap.add(2);
    heap.add(9);
    heap.deleteByIndex(0);
    XCTAssertFalse(heap.search(9));
}

- (void)testSearch {
    MaxHeap heap;
    heap.setLength(9);
    heap.add(3);
    heap.add(5);
    heap.add(2);
    heap.add(9);
    XCTAssertTrue(heap.search(5));
    XCTAssertFalse(heap.search(10));
}

- (void)testGenerateHeap {
    MaxHeap heap1;
    heap1.generateHeap(10);
    XCTAssertEqual(heap1.getHeapSize(), 10);
}

- (void)testLoadFromFile {
    MaxHeap heap2;
    heap2.loadFromFile("/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo-projekt/pliki/heap1.txt");
    XCTAssertTrue(heap2.search(1));
}

@end
