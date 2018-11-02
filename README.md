# struCtured-logger

struCtured-logger is a simple JSON logger for C applications. This first version only supports strings for the key types but I'm working on another version to support numbers and boolean values.

Lots of thanks to [Ayan George](https://github.com/ayang64) for the help with getting this where it is.

## Example 

Build the example:

```
make example
```

```c
#include "log.h"

int main(int argc, char **argv) {
    log_init(LOG_OUT_STDOUT);
    log(LOG_INFO, "msg", "records added successfully", "count", "2");
}
```

## Requirements

* [json-c](https://github.com/json-c/json-c) 

## Contact

Brian Downs [@bdowns328](http://twitter.com/bdowns328)

## License

Apache [License](/LICENSE).