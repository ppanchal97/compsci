import http.client

from enum import Enum


class HTTPLibraryInterface():
    def get(self, headers, payload, path):
        """Make a GET request to a given url"""
        pass

    def post(self, headers, payload, path):
        """Make a POST request to a given url"""
        pass

    def put(self, headers, payload, path):
        """Make a PUT request to a given url"""
        pass

    def patch(self, headers, payload, path):
        """Make a PATCH request to a given url"""
        pass

    def delete(self, headers, payload, path):
        """Make a DELETE request to a given url"""
        pass


class HTTPVerbs(Enum):
    get = "GET"
    post = "POST"
    put = "PUT"
    patch = "PATCH"
    delete = "DELETE"


class HTTPProxy(HTTPLibraryInterface):
    def __init__(self) -> None:
        super().__init__()

    def get(self, path, payload, headers):
        conn = http.client.HTTPSConnection("read-api.kortext.com")
        # TODO: use HTTPVerbs enum here
        conn.request("GET", path, payload, headers)
        res = conn.getresponse()

        return res

    def post(self, headers, payload, path) -> None:
        raise NotImplementedError

    def put(self, headers, payload, path) -> None:
        raise NotImplementedError

    def patch(self, headers, payload, path) -> None:
        raise NotImplementedError

    def delete(self, headers, payload, path) -> None:
        raise NotImplementedError


class FileHandler():
    def __init__(self) -> None:
        pass

    def create(file_name, path=None) -> None:
        f = open(f"{file_name}", "x")
        f.close()

    def append(file_name, content, path=None) -> None:
        f = open(file_name, "a")
        f.write(content)
        f.close()


class ScraperInterface():
    def save_html():
        """Save a webpage and output a html file"""
        pass

    def save_pdf():
        """Save a webpage and output a PDF file"""
        pass

    def save_json():
        """Save a webpage and output a JSON document"""
        pass


class KortextScraper(ScraperInterface):
    def __init__(self) -> None:
        pass

    def save_html(self, book_title, book_id, chapter_count) -> None:
        http_client = HTTPProxy()
        FileHandler.create(f"{book_title}.html")

        for i in range(0, chapter_count + 1):
            chapter_name = "introduction.xhtml"
            if i > 0 and i < 10:
                chapter_name = f"chapter0{i}.xhtml"
            elif i > 10:
                chapter_name = f"chapter{i}.xhtml"
            path = f"/mvc/e/{book_id}/OEBPS/{chapter_name}"
            print(path)
            payload = ''
            headers = {
                'Authorization': 'Bearer eyJhbGciOiJSUzI1NiIsImtpZCI6IjI1ODNCNTMyMjRBMzdGMjE2MTBDQzMzNDIzNDREN0VENUREMzlCNzgiLCJ0eXAiOiJKV1QifQ.eyJuYW1laWQiOiI4NzU0ODkiLCJrOnVzZXJpZCI6Ijg3NTQ4OSIsInVuaXF1ZV9uYW1lIjoicHBhbmNoMDRAc3R1ZGVudC5iYmsuYWMudWsiLCJlbWFpbCI6InBwYW5jaDA0QHN0dWRlbnQuYmJrLmFjLnVrIiwiazp1c2Vyc291cmNlIjoiRGVtYW5kUmVudGFsIiwiazpkaXNwbGF5bmFtZSI6IlNTTyBVU2VyIiwiazp1c2VydHlwZSI6IkN1c3RvbWVyIiwiazpvcmdpZCI6Ijk2IiwiazpvcmduYW1lIjoiQmlya2JlY2ssIFVuaXZlcnNpdHkgb2YgTG9uZG9uIiwiazphY2NlcHRlZHRlcm1zIjoiMTYyMDA2NzYxOSIsInJvbGUiOlsidXNlciIsImN1c3RvbWVyIl0sIm5iZiI6MTYyOTU0NDI0NSwiZXhwIjoxNjI5NTUxNDQ1LCJpYXQiOjE2Mjk1NDQyNDUsImlzcyI6ImtvcnRleHQiLCJhdWQiOiJyZWFkZXItYXBpIn0.gfnxtKzkTkRB0SSo9d4nxlE9cRidDuPpwtvjKfG8nFyBhJbCHlSO_EkaNbI_XaNunGdwjUzavNBKk73eU5fGfKESSwmvCupVLnPk5RxTsolb9RUyVRsyTKHVxneSKv-CbYEqeLXoP57WGxGtbdc3is96mt9hrhqtTyOWa8Xgq0DEnaWGjHXDp065l1sDlSVsnG98obCi3ks6-U8hBRGNtbLhNIVEK_GzUY-CAgOelhTzWHMFS5GEAH_rTyWDuzTe4OT5ursUlP9HpolCq7q5pz5lKkJIXZEs_LIUpneS7OKfHe9sUq7QC2KxObrftqwdgMSmOCxTbhmgTr82XvIzdw',
                'Cookie': 'ASP.NET_SessionId=q2birpsooceffmwqopcwlihw'
            }
            res = http_client.get(path, payload, headers)
            data = res.read()
            chapter_html = data.decode("utf-8")
            FileHandler.append((f"{book_title}.html"), chapter_html)


if __name__ == "__main__":
    k = KortextScraper()
    k.save_html(
        "Object_Oriented_Systems_Analysis_and_Design_using_UML", 210885, 2)
