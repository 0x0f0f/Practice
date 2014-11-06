package main

import (
    "fmt"
    "encoding/json"
)

type req struct {
    Data string
    Expire int
}

func main() {

    var ireq req

   // res := []byte(`{"value":"hello world","expire":123}`)
    res := `[123 35 118 97 108 117 101 34 58 34 104 101 108 108 111 32 119 111 114 108 100 34 44 32 34 101 120 112 105 114 101 34 58 49 50 51 125]`
        //
    fmt.Println(res)
    err := json.Unmarshal([]byte(res), &ireq)
    if err != nil {
        panic(err)
    }
    fmt.Printf("%s\n", res)
    fmt.Println(ireq.Data)
    fmt.Println(ireq.Expire)
}
