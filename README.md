# node-psdthumb
Use native code to extract embedded JPEG format thumbnails directly from PSD files, and do not depend on any modules except NAN

#Example
```
const psdthumb = require("psdthumb");
psdthumb('./in.psd','./out.jpg',(result)=> {
    console.log("done:" , result);
});
```
