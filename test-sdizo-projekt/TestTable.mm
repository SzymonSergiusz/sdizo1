#import <XCTest/XCTest.h>
#import "Table.hpp"

@interface TableTests : XCTestCase
@end

@implementation TableTests

- (void)testAddMethod {
    Table table;
    table.add(0, 10);
    table.add(1, 20);
    XCTAssertEqual(table.getSize(), 2);
    XCTAssertTrue(table.isContainingValue(10));
    XCTAssertTrue(table.isContainingValue(20));
}

- (void)testDeleteByIndexMethod {
    Table table;
    table.add(0, 10);
    table.add(1, 20);
    table.deleteByIndex(1);
    XCTAssertEqual(table.getSize(), 1);
    XCTAssertTrue(table.isContainingValue(10));
    XCTAssertFalse(table.isContainingValue(20));
}

- (void)testIsContainingValueMethod {
    Table table;
    table.add(0, 10);
    table.add(1, 20);
    XCTAssertTrue(table.isContainingValue(10));
    XCTAssertTrue(table.isContainingValue(20));
    XCTAssertFalse(table.isContainingValue(30));
}

@end
