const psdthumb = require("./index");
psdthumb('./in.psd','./out.jpg',(result)=> {
    console.log("done:" , result);
});
