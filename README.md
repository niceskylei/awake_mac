# Make your mac awake

Attention！ Only work for macos!!!

## example

```
import {disableScreenSleep, enableScreenSleep} from 'awake_mac'
let ok = disableScreenSleep("marklei");
console.log("disableScreenSleep", ok);
if (ok) {
    setTimeout(() => {
        console.log("enableScreenSleep", enableScreenSleep());
    }, 1000 * 180);
} else {
    console.warn("disableScreenSleep failed");
}
```

