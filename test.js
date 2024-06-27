// const { exec } = require("child_process");

// function compileAndExecuteCpp(filename, callback) {
//   // 调用gcc编译器编译cpp文件
//   exec(`g++ -Wall -o b.exe ${filename} -lmpt`, (error, stdout, stderr) => {
//     if (error) {
//       // 编译出错时返回错误信息
//       callback(error.message);
//       return;
//     }
//     if (stderr) {
//       // 如果有错误输出，也返回错误信息
//       callback(stderr);
//       return;
//     }
//     // 编译成功后执行生成的可执行文件
//     exec("./output", (error, stdout, stderr) => {
//       if (error) {
//         // 执行出错时返回错误信息
//         callback(error.message);
//         return;
//       }
//       if (stderr) {
//         // 如果有错误输出，也返回错误信息
//         callback(stderr);
//         return;
//       }
//       // 返回执行结果给回调函数
//       callback(null, stdout);
//     });
//   });
// }

// // 使用示例
// const filename = "example.cpp";
// compileAndExecuteCpp(filename, (error, output) => {
//   if (error) {
//     console.error("Error:", error);
//     return;
//   }
//   console.log("Output:", output);
// });

const addon = require("./build/Release/addon");

console.log("addon", addon);

console.log("Private key:", addon.getString());
