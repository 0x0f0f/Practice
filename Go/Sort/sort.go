package main

import "sort"
import "fmt"

type ByLenth []string
// implemented the sort interface Len, Swap, Les
func (s ByLenth) Len() int {
    return len(s)
}

func (s ByLenth) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s ByLenth) Less(i, j int) bool {
    return len(s[i]) < len(s[j])
}

func main() {
    strs := []string{ "c", "a", "b" }
    sort.Strings(strs) // in place sort
    fmt.Println("strings: ", strs)

    ints := []int{7, 2, 4}
    sort.Ints(ints)
    fmt.Println("Ints: ", ints)

    s := sort.IntsAreSorted(ints)
    fmt.Println("Sorted? ", s)

    fruits := []string{"peach", "banana", "kiwi"}
    sort.Sort(ByLenth(fruits))
    fmt.Println(fruits)
}
