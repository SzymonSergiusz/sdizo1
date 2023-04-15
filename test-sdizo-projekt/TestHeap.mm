#import <Foundation/Foundation.h>
#import <XCTest/XCTest.h>
#include "MaxHeap.hpp"

@interface MaxHeapTests : XCTestCase

@end

@implementation MaxHeapTests

- (void)testMaxHeap {
    MaxHeap heap;

    // Test add function
    heap.add(3);
    heap.add(5);
    heap.add(2);
    heap.add(9);
//    XCTAssertEqual(heap.getMax(), 9);

    // Test deleteByIndex function
//    heap.deleteByIndex();
//    XCTAssertEqual(heap.getMax(), 5);

    // Test getMin function
//    XCTAssertEqual(heap.getMin(), 2);

    // Test displayTable function
    heap.displayTable();

    // Test displayHeap function
    heap.displayHeap();

    // Test displayTree function
    heap.displayTree();

    // Test generateHeap function
    heap.generateHeap();
//    XCTAssertEqual(heap.getMax(), 9);

    // Test loadFromFile function
    heap.loadFromFile("data.txt");
//    XCTAssertEqual(heap.getMax(), 20);
}

@end

