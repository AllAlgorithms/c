/**
 * validate.js
 * 
 * The All ▲lgorithms validator CLI
 * 
 * Author: Carlos Abraham Hernandez.
 * https://abranhe.com (abraham@abranhe.com)
 */
'use strict';

const glob = require('glob');
const path = require('path');
const decamelize = require('decamelize');
const chalk = require('chalk');
const shell = require('child_process').execSync;

const getFiles = (src, callback) => {
  glob(src + '/**', callback);
};

getFiles('../', (err, res) => {
  if (err) {
    console.log('Error', err);
  } else {
    let invalid = false;
    res.map((file) => {
      // Accept only valid C++ Files (.cpp,.hpp,.h,c++)
      if (path.extname(file) !== '.c' && path.extname(file) !== '.hpp' && path.extname(file) !== '.h') {
        return;
      }

      if (file !== decamelize(file.replace(' ', ''))) {
        console.log(`${chalk.red(path.basename(file))} does not follow the correct style.`);
        let invalid = true;
      } else {
        console.log(`${chalk.green(path.basename(file))} is ok.`);
      }
    });
    if (invalid) {
      // Throw an error at the end of checking all files.
      throw new TypeError(`Expected the All ▲lgorithms structure.`);
    }
  }
});
