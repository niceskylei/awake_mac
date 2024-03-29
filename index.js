// const awake = require('bindings')('awake');
let awake = {}
const os = require('os');
if (os.platform() == 'darwin') {
    awake = require('./build/Release/awake.node')
} else {
    module.exports = {
        disableScreenSleep: (reason) => false,
        enableScreenSleep: () => false,
    }
    return
}

let lockId = null;
const disableScreenSleep = (reason) => {
    if (lockId == null) {
        lockId = awake.disableScreenSleep(reason)
        return lockId != null
    } else {
        return true
    }
}

const enableScreenSleep = () => {
    if (lockId == null) {
        return true
    } else {
        let ok = awake.enableScreenSleep(lockId)
        lockId = null
        return ok
    }
}

const openUrl = (url) => {
    return awake.openUrl(url)
}

function cleanup(callback) {

    // attach user callback to the process event emitter
    // if no callback, it will still exit gracefully on Ctrl-C
    callback = callback || noOp;
    process.on('cleanup', callback);

    // do app specific cleaning before exiting
    process.on('exit', function () {
        process.emit('cleanup');
    });

    // catch ctrl+c event and exit normally
    process.on('SIGINT', function () {
        process.exit(2);
    });

    //catch uncaught exceptions, trace, then exit normally
    process.on('uncaughtException', function (e) {
        process.exit(99);
    });
};
cleanup(() => {
    enableScreenSleep()
})

module.exports = {
    disableScreenSleep,
    enableScreenSleep,
    openUrl,
}



