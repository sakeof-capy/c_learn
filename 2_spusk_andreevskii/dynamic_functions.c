#include <stdio.h>
#include "dynamic_head.h"

Result sum_elements_of_array(int array[], int size)
{
    Result res;
    if (size > 0)
    {
        res.number = 0;
        for (int i = 0; i < size; i++)
        {
            res.number = res.number + array[i];
            res.verdict = 0;
        }
        return res; 
    }
    else
    {
        res.number = 0;
        res.verdict = 1;
        return res;
    }
}

Result find_minimal_elem_of_array(int array[], int size)
{
    Result res;
    if (size > 0)
    {
        res.number = array[0];
        for (int i = 0; i < size; i++)
        {
            if (array[i] < res.number)
            {
                res.number = array[i];
            }
        }
        res.verdict = 0;
        return res;
    }
    else
    {
        res.number = 0;
        res.verdict = 1;
        return res;
    }
}

Result find_maximal_elem_of_array(int array[], int size)
{
    Result res;
    if (size > 0)
    {
    res.number = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > res.number)
        {
            res.number = array[i];
        }
    }
    res.verdict = 0;
    return res;
    }
    else
    {
        res.number = 0;
        res.verdict = 1;
        return res;
    }
}

int reverse_array_of_integers(int array[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", array[i]);
    }
}