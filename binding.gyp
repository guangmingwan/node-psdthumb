{
  "targets": [
    {
      "target_name": "psdthumb",
      "sources": [ "psdthumb.cc", "lib_psdthumb.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
