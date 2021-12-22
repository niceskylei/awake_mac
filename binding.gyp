{
  "targets": [
    {
      "target_name": "awake",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "awake.cc"],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "conditions":[
      	["OS=='linux'", {
      	  "sources": [ "CCAwake.cc" ]
      	  }],
        ["OS=='win'", {
      	  "sources": [ "CCAwake.cc" ]
      	  }],  
      	["OS=='mac'", {
      	  "sources": [ "CCAwake.mm" ],
          "link_settings": {
            "libraries": ["/System/Library/Frameworks/Foundation.framework", "/System/Library/Frameworks/IOKit.framework"]
          }
      	}]
      ]
      
    }
  ]
}