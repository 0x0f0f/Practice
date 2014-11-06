package main

import "fmt"
import "time"
import "sync/atomic"
import "runtime"
// use atomic package to manage the state of the variables
func main() {

    var ops uint64 = 0

    for i := 0; i < 50; i++  {
        go func() {
            for j := 0; j<10; j++ {
                //atomic.AddUint64(&ops, 1)
                //ops += 1
                runtime.Gosched()
            }
        }()
    }

    time.Sleep(time.Second )

    opsFinal := atomic.LoadUint64(&ops)
    fmt.Println("ops:", opsFinal)
}
