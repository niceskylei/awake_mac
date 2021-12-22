{
  "targets": [
    {
      "target_name": "awake",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "conditions":[ 
      	["OS=='mac'", {
      	  "sources": [ "awake.cc", "CCAwake.mm" ],
          "include_dirs": [
            "<!@(node -p \"require('node-addon-api').include\")"
          ],
          "link_settings": {
            "libraries": ["/System/Library/Frameworks/Foundation.framework", "/System/Library/Frameworks/IOKit.framework"]
          }
      	}]
      ]
      
    }
  ]
}