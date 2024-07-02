import scrapy
from scrapy.crawler import CrawlerProcess

class NamuSpider(scrapy.Spider):
    name = "namu"

    def start_requests(self):
        urls = [
            "https://ko.wikipedia.org/wiki/%EC%B9%B4%EC%B9%B4%EC%98%A4"
        ]

        for url in urls:
            yield scrapy.Request(url = url, callback = self.parse)
        
    def parse(self, response):
        paragraphs = response.css(".mw-content-ltr.mw-parser-output > p")
        with open("result.txt", "w", encoding='utf8') as fp:
            text = ''.join(paragraphs.css("b::text, a::text, p::text").getall())
            text = text.strip()
            fp.write(text)

if __name__ == '__main__':
    process = CrawlerProcess()
    crawler = process.create_crawler(NamuSpider)
    process.crawl(crawler)
    process.start()