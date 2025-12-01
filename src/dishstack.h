//
// Created by ybsxm on 11/30/2025.
//

#ifndef A_STACK_OF_DISHES_MYSTACK_H
#define A_STACK_OF_DISHES_MYSTACK_H

#endif //A_STACK_OF_DISHES_MYSTACK_H
#include "dish.hpp"
const int MAX_VALUE = 300;
class DishStack {
private:
    Dish arr[MAX_VALUE];
    Dish* top;
    Dish* start;
public:
    DishStack() : arr{} {
        top = arr;
        start = arr;
    }
    bool is_empty()
    {
        return (top == start);
    }

    bool is_full()
    {
        return (start + MAX_VALUE == top);
    }
    void push(Dish dish)
    {
        if (!is_full())
        {
            *top = dish;
            top++;
        }
    }

    Dish pop()
    {
        if (!is_empty())
        {
            top--;
            Dish popped = *top;
            return popped;
        }
    }
    Dish peek()
    {
        if (!is_empty())
        {
            top--;
            Dish popped = *top;
            top++;
            return popped;
        }
    }
    int size() {
        return top - start;
    }

};