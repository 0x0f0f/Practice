package main

import "fmt"
import "time"

func main(){
    p := fmt.Println

    now := time.Now()
    p(now)

    then := time.Date(2013, 11, 17, 20, 23, 58, 525254, time.UTC)
    p(then)

    p(then.Year())
    p(then.Month())
    p(then.Day())
    p(then.Hour())
    p(then.Minute())
    p(then.Nanosecond())
    p(then.Location())
    p(then.Weekday())

    p(then.Before(now))
    p(then.After(now))
    p(then.Equal(now))

    diff := now.Sub(then)
    p(diff)

    p(diff.Hours())
    p(diff.Minutes())
    p(diff.Nanoseconds())

}
