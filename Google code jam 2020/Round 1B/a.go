package main

import (
    "fmt"
)

func main() {
    var t int
    fmt.Scan(&t)
    for i := 0; i < t; i++ {
        var x, y int
        fmt.Scan(&x, &y)
        ret := solve(x, y)
        fmt.Printf("Case #%d: %s\n", i + 1, ret)
    }
}

func solve(x int, y int) string {
    ret := make([]rune, 0)
    if dfs(x, y, &ret) {
        return string(ret)
    } else {
        return "IMPOSSIBLE"
    }
}

func dfs(x int, y int, cur *[]rune) bool {
    if x == 0 && y == 0 {
        return true
    } else if x % 2 != 0 && y % 2 == 0 {
        // need to check (0, 1) case, otherwise recursion is inf loop
        if y == 0 && x == 1 {
            *cur = append(*cur, 'E')
            return true
        } else if y == 0 && x == -1 {
            *cur = append(*cur, 'W')
            return true
        }
        // west
        *cur = append(*cur, 'W')
        if dfs((x + 1) / 2, y / 2, cur) {
            return true
        }
        // east
        (*cur)[len(*cur) - 1] = 'E'
        if dfs((x - 1) / 2, y / 2, cur) {
            return true
        }
    } else if x % 2 == 0 && y % 2 != 0 {
        // need to check (0, 1) case, otherwise recursion is inf loop
        if x == 0 && y == 1 {
            *cur = append(*cur, 'N')
            return true
        } else if x == 0 && y == -1 {
            *cur = append(*cur, 'S')
            return true
        }
        // south
        *cur = append(*cur, 'S')
        if dfs(x / 2, (y + 1) / 2, cur) {
            return true
        }
        // north
        (*cur)[len(*cur) - 1] = 'N'
        if dfs(x / 2, (y - 1) / 2, cur) {
            return true
        }
    }
    return false
}