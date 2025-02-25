from fastapi import FastAPI, Request
from fastapi.responses import JSONResponse
import time
import httpx

app = FastAPI()

def get_current_time():
    return int(time.time())

@app.get("/about.json")
async def about(request: Request):
    client_ip = request.client.host
    data = {
        "client": {
            "host": client_ip
        },
        "server": {
            "current_time": get_current_time(),
            "services": {
                "weather": "http://localhost:8000/weather",
            }
        },
    }
    return JSONResponse(content=data)

@app.get("/weather")
async def get_weather():
    api_key = ""
    lat, lon = 43.611015, 3.877171

    weather_api_url = f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={api_key}"

    async with httpx.AsyncClient() as client:
        response = await client.get(weather_api_url)

        if response.status_code == 200:
            weather_data = response.json()
            return JSONResponse(content=weather_data)
        else:
            return JSONResponse(content={"error": "Failed to fetch weather data"}, status_code=response.status_code)

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
