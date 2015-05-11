{
    "targets": [{
        "target_name"  : "max31855pi"
      , "include_dirs" : [
            "<!(node -p -e \"require('path').dirname(require.resolve('nan'))\")"
        ]
      , "cflags_cc"      : [ "-fexceptions" ]
      , "cflags_cc!"     : [ "-fno-exceptions" ]
      , "cflags"       : [
            "-fexceptions"
          , "-Wno-unused-variable"
        ]
      , "cflags!"      : [ "-fno-exceptions" ]
      , "conditions": [["OS=='mac'", {
            "xcode_settings": { "GCC_ENABLE_CPP_EXCEPTIONS": "YES" }
        }]]
      , "sources"      : [
            "src/bcm2835.c"
          , "src/max31855.cc"
          , "src/node_max31855.cc"
        ]
    }]
}
