// Implementation of Pascal's triangle in golang

package main

import (
    "fmt"
    "strings"
)

func nextRow(prevRow []int) []int {
    current := make([]int, 0, len(prevRow)+1)

    current = append(current, 1)

    for i := 1; i < len(prevRow); i++ {
        current = append(current, prevRow[i-1]+prevRow[i])
    }

    current = append(current, 1)

    return current
}

func Triangle(rows int) [][]int {
    triangle := [][]int{}
    if rows <= 0 {
        return triangle
    }
    triangle = append(triangle, []int{1})
    for i := 1; i < rows; i++ {
        triangle = append(triangle, nextRow(triangle[i-1]))
    }
    return triangle
}

func present(line []int) string {
    words := make([]string, len(line), len(line))
    for i, v := range line {
        words[i] = fmt.Sprintf("%4v ", v)
    }
    return strings.Join(words, " ")
}

func main() {
    tri := Triangle(10)
    for _, line := range tri {
        fmt.Println(present(line))
    }
}
