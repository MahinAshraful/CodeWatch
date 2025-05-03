from flask import Flask, request, jsonify
from flask_cors import CORS

# Import from detect.py
import detect

app = Flask(__name__)
CORS(app)


@app.route("/")
def home():
    return "Code Detection API is running!"


@app.route("/detect", methods=["POST"])
def detect_code():
    # Get code from request
    data = request.json
    if not data or "code" not in data:
        return jsonify({"error": "No code provided"}), 400

    # Set the code to test
    detect.code_to_test = data.get("code", "")

    try:
        # Run the enhanced detection
        result = detect.detect_ai_generated_enhanced(detect.code_to_test)

        if isinstance(result, dict):
            return jsonify(
                {
                    "original_similarity": float(result["original_similarity"]),
                    "ai_similarity": float(result["ai_similarity"]),
                    "difference": float(result["difference"]),
                    "result": result["result"],
                }
            )
        else:
            return jsonify({"error": result}), 500

    except Exception as e:
        return jsonify({"error": str(e)}), 500


if __name__ == "__main__":
    app.run(debug=True, host="0.0.0.0", port=3000)
