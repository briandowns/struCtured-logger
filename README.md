# struCtured-logger

struCtured-logger is a simple JSON logger for C applications. This first version only supports strings for the key types but I'm working on another version to support numbers and boolean values.

## Use

To use this library, call the `slog` macro. This macro takes a log level, a string key, and a slog value. The values supported are int, int64, double, and string. To use one of those as a value, the value needs to be passed as a parameter to one of the associated functions. Ie `slog_int64(6789)`.

## Example 

Build the example:

```
make example
```

```c
#include <stdio.h>

#include "src/slog.h"

int main(int argc, char **argv) {
    slog_init(stdout);
    slog(SLOG_INFO, "msg", slog_string("records added successfully"), "count", "2");
    slog(SLOG_INFO, "msg", slog_string("records added successfully"), "count", slog_int(2));
    slog(SLOG_INFO, "msg", slog_string("records added successfully"), "count", slog_int64(9223372036854775807));
    slog(SLOG_INFO, "msg", slog_string("records added partially"), "count", slog_int64(3.14));
    slog(SLOG_INFO, "msg", slog_string("record added successfully"), "name", slog_string("Brian"), "elapsed", slog_double(5.76)); 
}
```

Expected output:

```sh
{ "timestamp": 1541620673, "level": "info", "msg": "records added successfully" }
{ "timestamp": 1541620673, "level": "info", "msg": "records added successfully", "count": 2 }
{ "timestamp": 1541620673, "level": "info", "msg": "records added successfully", "count": 9223372036854775807 }
{ "timestamp": 1541620673, "level": "info", "msg": "records added partially", "count": 3 }
{ "timestamp": 1541620673, "level": "info", "msg": "record added successfully", "name": "Brian", "elapsed": 5.7599999999999998 }
```

## Requirements

* [json-c](https://github.com/json-c/json-c) 

Lots of thanks to [Ayan George](https://github.com/ayang64) for the help with getting this where it is.

## Contact

Brian Downs [@bdowns328](http://twitter.com/bdowns328)

## License

Apache [License](/LICENSE).