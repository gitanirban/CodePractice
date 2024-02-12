#include "gtest/gtest.h"
#include "SpScLockFreeQueue.hpp"

// Define the size of the queue to test
const size_t queueSize = 10;

// Test fixture for SpScLockFreeQueue testsC:\Users\X380\Documents\code\repo\CodePractice\googletest\googletest\src\gtest_main.cc
class SpScLockFreeQueueTest : public ::testing::Test {
protected:
  // Create a new queue for each test
  SpScLockFreeQueue<int, queueSize> queue;
};

// Test that the queue is initially empty
TEST_F(SpScLockFreeQueueTest, InitiallyEmpty) {
  EXPECT_TRUE(queue.empty());
}

// Test that pushing an element works and increases the size
TEST_F(SpScLockFreeQueueTest, PushElement) {
  int element = 10;
  EXPECT_TRUE(queue.push(element));
  EXPECT_FALSE(queue.empty());
  EXPECT_EQ(queue.size(), 1);
}

// Test that pushing to a full queue fails
TEST_F(SpScLockFreeQueueTest, PushFullQueue) {
  // Fill the queue
  for (int i = 0; i < queueSize; ++i) {
    EXPECT_TRUE(queue.push(i));
  }

  // Push to a full queue should fail
  int element = 10;
  EXPECT_FALSE(queue.push(element));
  EXPECT_EQ(queue.size(), queueSize);
}

// Test that popping an element works and decreases the size
TEST_F(SpScLockFreeQueueTest, PopElement) {
  int element = 10;
  queue.push(element);
  int poppedElement;
  EXPECT_TRUE(queue.pop(poppedElement));
  EXPECT_TRUE(queue.empty());
  EXPECT_EQ(poppedElement, element);
}

// Test that popping from an empty queue fails
TEST_F(SpScLockFreeQueueTest, PopEmptyQueue) {
  int element;
  EXPECT_FALSE(queue.pop(element));
  EXPECT_TRUE(queue.empty());
}

// Test that clear empties the queue
TEST_F(SpScLockFreeQueueTest, Clear) {
  for (int i = 0; i < queueSize; ++i) {
    queue.push(i);
  }
  queue.clear();
  EXPECT_TRUE(queue.empty());
  EXPECT_EQ(queue.size(), 0);
}

// Test that max_size returns the correct value
TEST_F(SpScLockFreeQueueTest, MaxSize) {
  EXPECT_EQ(queue.max_size(), queueSize - 1);
}

// Test that size returns the correct number of elements
TEST_F(SpScLockFreeQueueTest, Size) {
  for (int i = 0; i < 5; ++i) {
    queue.push(i);
  }
  EXPECT_EQ(queue.size(), 5);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
