package main

import (
    "os"
    "fmt"
    "net"
)

func main(){
    hostname, err := os.Hostname()
    if err== nil {
        fmt.Println(hostname)
        ip, err := net.LookupIP(hostname)
        fmt.Println(ip, err)
    } else {
        panic(err)
    }
}
