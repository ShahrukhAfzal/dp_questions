const rp = require("request-promise");
const $ = require("cheerio");
const url = "https://www.moneycontrol.com/markets/indian-indices/";
const data = [];

const { MongoClient } = require("mongodb");
const uri = "mongodb://localhost:27017";
async function connect(data) {
  const client = new MongoClient(uri);
  try {
    await client.connect();
    const db = client.db("stocks_db_using_node");
    const indian_market = db.collection("indian_market");
    indian_market.insertMany(data);
    // console.log(data);
    console.log("connected to the $");
  } catch (ex) {
    console.log("something went wrong");
  } finally {
    client.close();
  }
}

rp(url)
  .then(function (html) {
    $("table.responsive tbody tr", html).each((i, elem) => {
      row = $(elem).text().split("\n");
      const row_data = {
        company: row[1].trim(),
        ltp: row[2].trim(),
        change_percent: row[3].trim(),
        volume: row[4].trim(),
        buy_price: row[5].trim(),
        sell_price: row[6].trim(),
        buy_qty: row[7].trim(),
        sell_qty: row[8].trim(),
      };
      if (i != 0) {
        data.push(row_data);
      }
    });
    connect(data);
  })
  .catch(function (err) {
    console.log(err);
  });
