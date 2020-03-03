MAX_CHANGE = 10;
audio_values = readvars('val.txt');

plot(audio_values)

previous_gradient = 0;
gradient = 0;
for i = 1 : length(audio_values)
    if i > 1
        previous_gradient = gradient;
        gradient = audio_values(i-1)-audio_values(i);
        
        % Determine gradient change
        % Percentage change
        change = abs(gradient - previous_gradient) / ...
            ((gradient + previous_gradient) / 2);
        % Scale by gradient size
        change = abs(change) * (abs(previous_gradient));
        
        if change > MAX_CHANGE
            fprintf("Found peak at: (%d, %g)\n", i-1, audio_values(i-1))
            fprintf("Repairing...\n")
            
            audio_values(i-1) = (audio_values(i-2)+audio_values(i))/2;
            fprintf("New value: %g\n\n", audio_values(i-1))
        end
    end
end

hold on
plot(audio_values)