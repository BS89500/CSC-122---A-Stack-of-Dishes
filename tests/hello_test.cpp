#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"
#include "../src/dishstack.h"

TEST_CASE("DishStack operations - matches driver code output", "[dishstack][dish]") {

    SECTION("Initial stack size should be zero") {
        DishStack stack;
        int stack_size = stack.size();

        // Expected output: 0
        REQUIRE(stack_size == 0);
    }

    SECTION("Stack size after pushing four dishes should be four") {
        DishStack stack;
        Dish one_dish = Dish("A dish with one fish pattern on it");
        Dish two_dish = Dish("A dish with two fish patterns on it");
        Dish red_dish = Dish("A dish with a red fish pattern on it");
        Dish blue_dish = Dish("A dish with a blue fish pattern on it");

        stack.push(one_dish);
        stack.push(two_dish);
        stack.push(red_dish);
        stack.push(blue_dish);

        int size_after_pushes = stack.size();

        // Expected output: 4
        REQUIRE(size_after_pushes == 4);
    }

    SECTION("Peek should return top dish without removing it") {
        DishStack stack;
        Dish one_dish = Dish("A dish with one fish pattern on it");
        Dish two_dish = Dish("A dish with two fish patterns on it");
        Dish red_dish = Dish("A dish with a red fish pattern on it");
        Dish blue_dish = Dish("A dish with a blue fish pattern on it");

        stack.push(one_dish);
        stack.push(two_dish);
        stack.push(red_dish);
        stack.push(blue_dish);

        Dish peeked_dish = stack.peek();

        // Expected output: "A dish with a blue fish pattern on it"
        REQUIRE(peeked_dish.get_description() == "A dish with a blue fish pattern on it");

        // Verify size hasn't changed after peek
        REQUIRE(stack.size() == 4);
    }

    SECTION("Pop should return and remove top dish") {
        DishStack stack;
        Dish one_dish = Dish("A dish with one fish pattern on it");
        Dish two_dish = Dish("A dish with two fish patterns on it");
        Dish red_dish = Dish("A dish with a red fish pattern on it");
        Dish blue_dish = Dish("A dish with a blue fish pattern on it");

        stack.push(one_dish);
        stack.push(two_dish);
        stack.push(red_dish);
        stack.push(blue_dish);

        Dish popped_dish = stack.pop();

        // Expected output: "A dish with a blue fish pattern on it"
        REQUIRE(popped_dish.get_description() == "A dish with a blue fish pattern on it");

        // Verify size decreased
        REQUIRE(stack.size() == 3);
    }

    SECTION("Second pop should return red dish") {
        DishStack stack;
        Dish one_dish = Dish("A dish with one fish pattern on it");
        Dish two_dish = Dish("A dish with two fish patterns on it");
        Dish red_dish = Dish("A dish with a red fish pattern on it");
        Dish blue_dish = Dish("A dish with a blue fish pattern on it");

        stack.push(one_dish);
        stack.push(two_dish);
        stack.push(red_dish);
        stack.push(blue_dish);

        stack.pop(); // Remove blue dish
        Dish another_popped_dish = stack.pop();

        // Expected output: "A dish with a red fish pattern on it"
        REQUIRE(another_popped_dish.get_description() == "A dish with a red fish pattern on it");
    }

    SECTION("Final size after two pops should be two") {
        DishStack stack;
        Dish one_dish = Dish("A dish with one fish pattern on it");
        Dish two_dish = Dish("A dish with two fish patterns on it");
        Dish red_dish = Dish("A dish with a red fish pattern on it");
        Dish blue_dish = Dish("A dish with a blue fish pattern on it");

        stack.push(one_dish);
        stack.push(two_dish);
        stack.push(red_dish);
        stack.push(blue_dish);

        stack.pop(); // Remove blue dish
        stack.pop(); // Remove red dish

        int final_size = stack.size();

        // Expected output: 2
        REQUIRE(final_size == 2);
    }

    SECTION("Complete driver code scenario") {
        DishStack stack;
        Dish one_dish = Dish("A dish with one fish pattern on it");
        Dish two_dish = Dish("A dish with two fish patterns on it");
        Dish red_dish = Dish("A dish with a red fish pattern on it");
        Dish blue_dish = Dish("A dish with a blue fish pattern on it");

        // Initial size: 0
        int stack_size = stack.size();
        REQUIRE(stack_size == 0);

        stack.push(one_dish);
        stack.push(two_dish);
        stack.push(red_dish);
        stack.push(blue_dish);

        // Size after pushes: 4
        int size_after_pushes = stack.size();
        REQUIRE(size_after_pushes == 4);

        // Peek: "A dish with a blue fish pattern on it"
        Dish peeked_dish = stack.peek();
        REQUIRE(peeked_dish.get_description() == "A dish with a blue fish pattern on it");

        // Pop: "A dish with a blue fish pattern on it"
        Dish popped_dish = stack.pop();
        REQUIRE(popped_dish.get_description() == "A dish with a blue fish pattern on it");

        // Another pop: "A dish with a red fish pattern on it"
        Dish another_popped_dish = stack.pop();
        REQUIRE(another_popped_dish.get_description() == "A dish with a red fish pattern on it");

        // Final size: 2
        int final_size = stack.size();
        REQUIRE(final_size == 2);

        INFO("Expected output sequence: 0, 4, blue fish, blue fish, red fish, 2");
    }

    SECTION("Verify LIFO (Last In First Out) order") {
        DishStack stack;
        Dish one_dish = Dish("A dish with one fish pattern on it");
        Dish two_dish = Dish("A dish with two fish patterns on it");
        Dish red_dish = Dish("A dish with a red fish pattern on it");
        Dish blue_dish = Dish("A dish with a blue fish pattern on it");

        stack.push(one_dish);
        stack.push(two_dish);
        stack.push(red_dish);
        stack.push(blue_dish);

        // Pop in reverse order of push
        REQUIRE(stack.pop().get_description() == "A dish with a blue fish pattern on it");
        REQUIRE(stack.pop().get_description() == "A dish with a red fish pattern on it");
        REQUIRE(stack.pop().get_description() == "A dish with two fish patterns on it");
        REQUIRE(stack.pop().get_description() == "A dish with one fish pattern on it");

        // Stack should now be empty
        REQUIRE(stack.size() == 0);
    }
}