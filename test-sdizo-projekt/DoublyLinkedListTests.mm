#import <XCTest/XCTest.h>
#include "DoublyLinkedList.hpp"

@interface DoublyLinkedListTests : XCTestCase
@end

@implementation DoublyLinkedListTests

- (void)testAdd {
    DoublyLinkedList list;
    list.add(5, 0);
    list.add(3, 1);
    list.add(9, 0);
    list.add(2, 2);
    XCTAssertEqual(list.getSize(), 4);
}

- (void)testDeleteByValue {
    DoublyLinkedList list;
    list.add(5, 0);
    list.add(3, 1);
    list.add(9, 0);
    list.add(2, 2);
    list.deleteByValue(9);
    list.deleteByValue(2);
    XCTAssertEqual(list.getSize(), 2);
}

- (void)testClear {
    DoublyLinkedList list;
    list.add(5, 0);
    list.add(3, 1);
    list.add(9, 0);
    list.add(2, 2);
    list.clear();
    XCTAssertEqual(list.getSize(), 0);
}

- (void)testIsContainingValue {
    DoublyLinkedList list;
    list.add(5, 0);
    list.add(3, 1);
    list.add(9, 0);
    list.add(2, 2);
    XCTAssertTrue(list.isContainingValue(5));
    XCTAssertFalse(list.isContainingValue(7));
}

- (void)testLoadFromFile {
    DoublyLinkedList list;
    list.loadFromFile("test.txt");
    XCTAssertEqual(list.getSize(), 4);
}

- (void)testGenerateList {
    DoublyLinkedList list;
    list.generateList(5);
    XCTAssertEqual(list.getSize(), 5);
}

@end
