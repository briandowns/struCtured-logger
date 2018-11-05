# struCtured-logger

struCtured-logger is a simple JSON logger for C applications. This first version only supports strings for the key types but I'm working on another version to support numbers and boolean values.

Lots of thanks to [Ayan George](https://github.com/ayang64) for the help with getting this where it is.

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
    slog(SLOG_INFO, "msg", "records added successfully", "count", "2");
    slog(SLOG_INFO, "msg", "records added successfully", "count", slog_field_int(2));
    slog(SLOG_INFO, "msg", "records added successfully", "count", slog_field_int64(9223372036854775807));
    slog(SLOG_INFO, "msg", "records added partially", "count", slog_field_int64(3.14));
    slog(SLOG_INFO, "msg", "record added successfully", "name", slog_field_string("Brian"), "elapsed", slog_field_double(5.76)); 
}

```

## Requirements

* [json-c](https://github.com/json-c/json-c) 

## Contact

Brian Downs [@bdowns328](http://twitter.com/bdowns328)

## License

Apache [License](/LICENSE).