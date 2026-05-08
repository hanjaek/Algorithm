-- 코드를 입력하세요
SET @HOUR = -1;

SELECT (@HOUR := @HOUR + 1) as HOUR,
    (
        SELECT COUNT(*)
        FROM ANIMAL_OUTS
        WHERE HOUR(DATETIME) = @HOUR
    ) as COUNT
FROM ANIMAL_OUTS
WHERE @HOUR < 23